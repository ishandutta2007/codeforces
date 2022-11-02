var
  a:array[0..500500]of longint;
  j,n,i,x,nx:longint;
  s:ansistring;

begin
  readln(s);
  n:=length(s);
  for i:=1 to n do begin
    x:=ord(s[i]);
    nx:=0;
    for j:=1 to 8 do begin
      nx:=nx*2+(x and 1);
      x:=x shr 1;
    end;
    a[i]:=nx;
  end;
  a[0]:=0;
  for i:=1 to n do writeln((a[i-1]-a[i]+256)mod 256);
end.