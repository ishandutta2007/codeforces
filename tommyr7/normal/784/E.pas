var a,b,c,d,x,y,z,w:longint;
begin
  readln(a);
  readln(b);
  readln(c);
  readln(d);
  x:=(a xor b)and(c or d);
  y:=(b and c)or(a xor d);
  writeln(x xor y);
end.