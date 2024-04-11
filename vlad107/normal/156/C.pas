const
  base=1000000007;

var
  j,c,n,m,tt,i:longint;
  s:ansistring;
  a:array[0..11111]of longint;
  f:array[0..111,0..2666]of longint;

begin
  readln(tt);
  fillchar(f,sizeof(f),$0);
  f[0][0]:=1;
  for i:=0 to 100 do 
    for j:=0 to 2600 do
      if (f[i][j]<>0)then 
        for c:=1 to 26 do begin
          inc(f[i+1][j+c],f[i][j]);
          if (f[i+1][j+c]>=base)then dec(f[i+1][j+c],base);
        end;
  
  while (tt>0)do begin
    dec(tt);
    readln(s);
    n:=length(s);
    for i:=1 to n do a[i]:=ord(s[i])-96;
    m:=0;
    for i:=1 to n do inc(m,a[i]);
    writeln((f[n][m]-1+base)mod base);
  end;
end.