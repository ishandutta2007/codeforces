var
  n,x,y,i:longint;
  s:ansistring;
  a:array[0..500500]of longint;
begin
  readln(s);
  for i:=1 to length(s)-1 do a[i]:=a[i-1]+ord(s[i]=s[i+1]);
  readln(n);
  for i:=1 to n do begin
    read(x,y);
    writeln(a[y-1]-a[x-1]);
  end;
end.