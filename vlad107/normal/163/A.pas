{$r-,q-,s-,i-,o+}
const
  base=1000000007;

var
  q,next,res,n,m,i,j:longint;
  s,t:ansistring;
  f:array[0..5005,0..5005,0..1]of longint;

begin
  readln(s);
  readln(t);
  n:=length(s);
  m:=length(t);
  fillchar(F,sizeof(f),$0);
  for i:=1 to n do 
    f[i][1][0]:=1;
      
  for i:=1 to n+1 do 
    for j:=1 to m do for q:=0 to 1 do 
      if (f[i][j][q]<>0)then begin
        if (i<=n)and(s[i]=t[j])then begin
          inc(f[i+1][j+1][1],f[i][j][q]);
          if (f[i+1][j+1][1]>=base)then dec(f[i+1][j+1][1],base);
        end;
        inc(f[i][j+1][q],f[i][j][q]);
        if (f[i][j+1][q]>=base)then dec(f[i][j+1][q],base);
      end;
  res:=0;
  for i:=1 to n+1 do begin
    inc(res,f[i][m+1][1]);
    if (res>=base)then dec(res,base);
  end;
  writeln(res);
end.