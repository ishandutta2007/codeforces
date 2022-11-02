{$r-,q-,s-,i-,o+}
const
  ABC='6789TJQKA';
var
  ch,c1,c2,c3,c4:char;
  x,y:longint;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  readln(ch);
  readln(c3,c4,c1,c1,c2);
  x:=pos(c1,ABC);
  y:=pos(c3,ABC);
  if (c2=c4)
    then if (y>x)then writeln('YES')else writeln('NO')
    else if (c4=ch)then writeln('YES')else writeln('NO');
end.