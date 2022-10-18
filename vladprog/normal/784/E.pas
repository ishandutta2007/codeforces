var
  a,b,c,d:byte;
  su,sv,si:char;

function f(x,y:byte;s:char):byte;
begin
  case s of
    'a': f:=x and y;
    'o':  f:=x or  y;
    'x': f:=x xor y
  end
end;

function v(x,y:byte):byte;
begin
  v:=f(x,y,sv)
end;

function i(x,y:byte):byte;
begin
  i:=f(x,y,si)
end;

function u(x,y:byte):byte;
begin
  u:=f(x,y,su)
end;

begin
  readln(a,b,c,d);
  {write('I>  ');
  readln(sv);
  write('II> ');
  readln(si);
  write('D   ');
  readln(su);}
  sv:='x';
  si:='o';
  su:='a';
  writeln(v(u(v(a,b),i(c,d)),i(u(b,c),v(a,d))))
end.