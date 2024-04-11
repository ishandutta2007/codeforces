var
  ans,cr,i:longint;
  s:ansistring;
  f:array[0..500500]of longint;

begin
  readln(s);
  f[0]:=0;
  for i:=1 to length(s)do 
    f[i]:=f[i-1]+ord(s[i]in['A'..'Z']);
  ans:=length(s);
  for i:=0 to length(s)do begin
    cr:=(i-f[i])+(f[length(s)]-f[i]);
    if (cr<ans)then ans:=cr;
  end;
  writeln(ans);
end.