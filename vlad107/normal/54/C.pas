var
  g:array[0..22,0..5]of int64;
  f:array[0..1111,0..1111]of extended;
  cp:array[0..1111]of extended;
  res:extended;
  k,i,j,n:longint;
  x,ll,rr:int64;
  function kol1(x:int64):int64;
    var
      s:string;
      q,i,j:longint;
      st10,res:int64;
    begin
      if (x=0)then begin
        kol1:=0;
        exit;
      end;
      str(x,s);
      fillchar(g,sizeof(g),$0);
      if (s[1]='1')then g[2][0]:=1 else g[2][1]:=1;
      for i:=2 to length(s)do
        for j:=0 to 2 do begin
          if (g[i][j]=0)then continue;
          if (j=0)then begin
            for q:=0 to ord(s[i])-49 do inc(g[i+1][1],g[i][j]);
            inc(g[i+1][0],g[i][j]);
          end else
            if (j=1)then for q:=0 to 9 do inc(g[i+1][1],g[i][j]);
        end;
      res:=g[length(s)+1][0]+g[length(s)+1][1];
      st10:=1;
      for i:=1 to length(s)-1 do begin
        inc(res,st10);
        st10:=st10*10;
      end;
      kol1:=res;
    end;
begin
  read(n);
  for i:=1 to n do begin
    read(ll,rr);
    x:=kol1(rr)-kol1(ll-1);
    cp[i]:=x/(rr-ll+1);
  end;
  read(k);
  for i:=1 to n+1 do
    for j:=0 to n do f[i][j]:=0;
  f[1][0]:=1;
  for i:=1 to n do
    for j:=0 to n do if (f[i][j]>0)then begin
      f[i+1][j]:=f[i+1][j]+f[i][j]*(1-cp[i]);
      if (j<n)then f[i+1][j+1]:=f[i+1][j+1]+f[i][j]*cp[i];
    end;
  res:=0;
  for j:=0 to n do
    if (j*100>=n*k)then res:=res+f[n+1][j];
  writeln(res:0:20);
end.