var
  res,n,i,j:longint;
  x,min,a,b:string;
  tmp:char;
  s:array[1..1111] of string;

begin
  readln(n);
  for i:=1 to n do begin
    readln(a);
    readln(b);
    if (i<n)then readln;
    x:=a+b;
    min:='9999';
    for j:=1 to 4 do begin
      if (x<min)then min:=x;
      tmp:=a[1];
      a[1]:=b[1];
      b[1]:=b[2];
      b[2]:=a[2];
      a[2]:=tmp;
      x:=a+b;
    end;
    s[i]:=min;
  end;
  for i:=1 to n-1 do
    for j:=1 to n-1 do
      if (s[j]>s[j+1])then begin
        x:=s[j];s[j]:=s[j+1];s[j+1]:=x;
      end;
  res:=1;
  for i:=2 to n do
    if (s[i]<>s[i-1])then inc(res);
  writeln(res);
end.