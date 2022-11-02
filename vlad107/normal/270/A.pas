var
  ans:ansistring;
  tt,a,t:longint;

begin
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(a);
    ans:='NO';
    for t:=3 to 100500 do
      if (180*(t-2)=t*a)then begin
        ans:='YES';
        break;
      end;
    writeln(ans);
  end;
end.