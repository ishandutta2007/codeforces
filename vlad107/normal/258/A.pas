var
  s:ansistring;
  x,i:longint;

begin
  readln(s);
  x:=1;
  for i:=1 to length(s)do if (s[i]='0')then begin x:=i;break; end;
  delete(s,x,1);
  i:=1;
  while (i<length(s))and(s[i]='0')do inc(i);
  writeln(copy(s,i,length(s)));
end.