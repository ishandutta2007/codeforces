{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a: array [0..110,0..110] of longint;
  n,m,tmp,i,j: longint;
  flag: boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  if n > m then
  begin
    tmp:=n; n:=m; m:=tmp;
    flag:=True;
  end
  else flag:=False;
  if (n = 1) and (m = 1) then writeln(1) else
  if (n = 1) and (m < 4) then writeln(-1) else
  if (n = 2) and (m = 2) then writeln(-1) else
  begin
    if m = 3 then
    begin
      a[1,1]:=3; a[1,2]:=6; a[1,3]:=2;
      a[2,1]:=5; a[2,2]:=1; a[2,3]:=4;
      a[3,1]:=9; a[3,2]:=7; a[3,3]:=8;
      if n = 3 then
      begin
        a[2,3]:=8;
        a[3,3]:=4;
      end;
    end else
    begin
      i:=2; j:=0;
      while i <= m do
      begin
        inc(j);
        a[1,j]:=i;
        inc(i,2);
      end;
      i:=1;
      while i <= m do
      begin
        inc(j);
        a[1,j]:=i;
        inc(i,2);
      end;
      for i:=2 to n do
        for j:=1 to m do a[i,j]:=a[i-1,j]+m;
    end;
    if flag then
    begin
      for i:=1 to m do
      begin
        for j:=1 to n-1 do write(a[j,i],' ');
        writeln(a[n,i]);
      end;
    end else
    begin
      for i:=1 to n do
      begin
        for j:=1 to m-1 do write(a[i,j],' ');
        writeln(a[i,m]);
      end;
    end;
  end;
  close(input);
  close(output);
end.