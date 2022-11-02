var
  tt:longint;
  s:ansistring;

begin
  readln(tt);
  while (tt>0)do begin
    dec(tt);
    readln(s);
    if (copy(s,1,5)='miao.')and(copy(s,length(s)-4,5)<>'lala.')then writeln('Rainbow''s')else
    if (copy(s,length(s)-4,5)='lala.')and((copy(s,1,5)<>'miao.'))then writeln('Freda''s')else
    writeln('OMG>.< I don''t know!');
  end;
end.