var
  s:string;
  x,y:longint;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  readln(s);
  readln(x);
  y:=ord(s[1]='f');
  if (y=0)then x:=3-x;
  if (x=1)then writeln('L')else writeln('R');
  close(output);close(input);
end.