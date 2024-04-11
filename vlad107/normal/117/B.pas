{$r-,q-,s-,i-,o+}
var
  x,a,b,m,i:longint;
  s:string;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(a,b,m);
  if (a>m)then a:=m;
  for i:=0 to a do begin
    x:=int64(i)*1000000000 mod m;
    x:=m-x;
    if (x=m)then x:=0;
    if (x<=b)then continue;
    write('1 ');
    str(i,s);
    while (length(s)<9)do s:='0'+s;
    writeln(s);
    halt(0);
  end;
  writeln(2);
end.