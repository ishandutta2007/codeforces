var
  t1,t2,s:ansistring;
  i,j:longint;
  ch:char;
  x,y:boolean;
  function ok(t1,t2,s:ansistring):boolean;
    begin
      if (pos(t1,s)=0)then ok:=false else begin
        delete(s,1,pos(t1,s)+length(t1)-1);
        ok:=pos(t2,s)>0;
      end;
    end;
begin
  readln(s);
  readln(t1);
  readln(t2);
  x:=ok(t1,t2,s);
  i:=1;j:=length(s);
  while (i<j)do begin
    ch:=s[i];s[i]:=s[j];s[j]:=ch;
    inc(i);dec(j);
  end;
  y:=ok(t1,t2,s);
  if (x)and(y)then writeln('both')else
  if (not x)and(not y)then writeln('fantasy')else
  if (not x)and(y)then writeln('backward')else
  writeln('forward');
end.