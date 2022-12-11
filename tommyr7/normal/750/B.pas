var n,i,j,now,op:longint;
    ch:char;
	s:string;
begin
  readln(n);
  now:=0;
  for i:=1 to n do
  begin
    read(op);
    read(ch);
    readln(s);
    if (now=0) and (s<>'South') then
	begin
	  writeln('NO');
	  halt;
	end;
	if (now=20000) and (s<>'North') then
	begin
	  writeln('NO');
	  halt;
	end;
    if (s='South') then
    begin
	  now:=now+op;
	  if (now>20000) then
	  begin
	    writeln('NO');
	    halt;
	  end;
	  now:=now mod 40000;
	end;
	if (s='North') then
	begin
	  now:=now-op;
	  if (now<0) then
	  begin
	    writeln('NO');
	    halt;
	  end;
	  now:=now mod 40000;
	end;
  end;
  if (now=0) then writeln('YES') else writeln('NO');
end.