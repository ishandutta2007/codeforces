var
  q,s,p:string;
  i,n:longint;

begin
  readln(p);
  readln(n);
  q:='~';
  for i:=1 to n do begin
    readln(s);
    if (pos(p,s)<>1)then continue;
    if (q='~')or(s<q)then q:=s;
  end;
  if (q='~')
    then writeln(p)
    else writeln(q);
end.