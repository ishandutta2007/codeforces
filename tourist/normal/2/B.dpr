{$R-,S-,Q-,I-,O+}
var
  f,pr: array [0..1010,0..1010] of longint;
  r: array [0..1010,0..1010,0..1] of longint;
  ci,cj,ans,kp,n,i,j,a,x,q: longint;
  p: array [0..2010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  ci:=0; cj:=0;
  for i:=1 to n do
    for j:=1 to n do
    begin
      read(a);
      if a = 0 then
      begin
        r[i,j,0]:=1000000;
        r[i,j,1]:=1000000;
        ci:=i;
        cj:=j;
      end else
      begin
        r[i,j,0]:=0; x:=a;
        while x and 1 = 0 do
        begin
          inc(r[i,j,0]);
          x:=x shr 1;
        end;
        r[i,j,1]:=0; x:=a;
        while x mod 5 = 0 do
        begin
          inc(r[i,j,1]);
          x:=x div 5;
        end;
      end;
    end;
  ans:=maxlongint; kp:=0;
  for q:=0 to 1 do
  begin
    fillchar(f,sizeof(f),0);
    fillchar(pr,sizeof(pr),0);
    f[1,1]:=r[1,1,q];
    for i:=1 to n do
      for j:=1 to n do
        if i+j = 2 then continue else
        if i = 1 then
        begin
          f[i,j]:=f[i,j-1]+r[i,j,q];
          pr[i,j]:=2;
        end else
        if j = 1 then
        begin
          f[i,j]:=f[i-1,j]+r[i,j,q];
          pr[i,j]:=1;
        end else
        if f[i-1,j] < f[i,j-1] then
        begin
          f[i,j]:=f[i-1,j]+r[i,j,q];
          pr[i,j]:=1;
        end else
        begin
          f[i,j]:=f[i,j-1]+r[i,j,q];
          pr[i,j]:=2;
        end;
    if f[n,n] < ans then
    begin
      ans:=f[n,n];
      kp:=0; i:=n; j:=n;
      while i+j > 2 do
      begin
        inc(kp);
        p[kp]:=pr[i,j];
        if p[kp] = 1 then dec(i)
        else dec(j);
      end;
    end;
  end;
  if (ans > 1) and (ci > 0) then
  begin
    writeln(1);
    for i:=1 to ci-1 do write('D');
    for i:=1 to cj-1 do write('R');
    for i:=ci to n-1 do write('D');
    for i:=cj to n-1 do write('R');
    writeln;
  end else
  begin
    writeln(ans);
    for i:=kp downto 1 do
      if p[i] = 1 then write('D')
      else write('R');
    writeln;
  end;
  close(input);
  close(output);
end.