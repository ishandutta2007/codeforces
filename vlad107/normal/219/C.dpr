const
  inf=1000000000;

var
  pred,f:array[0..555555,0..26]of longint;
  s:ansistring;
  a:array[0..555555]of longint;
  k,c1,c2,ch,i,n,min1,min2:longint;

begin
  readln(n,k);
  readln(s);
  for i:=1 to n do a[i]:=ord(s[i])-ord('A')+1;
  fillchar(f,sizeof(f),$FF);
  for ch:=1 to k do
    f[1][ch]:=ord(ch<>a[1]);
  for i:=2 to n do begin
    min1:=inf;min2:=inf;
    c1:=0;c2:=0;
    for ch:=1 to k do 
      if (f[i-1][ch]<=min1)
        then begin
          min2:=min1;c2:=c1;
          min1:=f[i-1][ch];c1:=ch;
        end else
      if (f[i-1][ch]<min2)
        then begin
          min2:=f[i-1][ch];c2:=ch;
        end;
    for ch:=1 to k do 
      if (ch=c1)then begin
        pred[i][ch]:=c2;
        f[i][ch]:=min2+ord(ch<>a[i]);
      end else begin
        pred[i][ch]:=c1;
        f[i][ch]:=min1+ord(ch<>a[i]);
      end;
  end;
  min1:=inf;
  for ch:=1 to k do 
    if (f[n][ch]<min1)then begin
      min1:=f[n][ch];
      c1:=ch;
    end;
  writeln(min1);
  for i:=n downto 1 do begin
    a[i]:=c1;
    c1:=pred[i][c1];
  end;
  for i:=1 to n do write(chr(a[i]+ord('A')-1));
  writeln;
end.