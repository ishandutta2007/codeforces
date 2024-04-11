var
  s,p:ansistring;
  t:longint;

begin
  readln(s);
  if (copy(s,1,3)='ftp')then begin
    p:='ftp://';
    delete(s,1,3);
  end else begin
    p:='http://';
    delete(s,1,4);
  end;
  t:=pos('ru',s);
  if (t=1)then begin
    p:=p+'ru';
    delete(s,1,2);
  end;
  t:=pos('ru',s);
  p:=p+copy(s,1,t-1)+'.ru';
  delete(s,1,t+1);
  if (length(s)<>0)then p:=p+'/'+s;
  writeln(p);
end.