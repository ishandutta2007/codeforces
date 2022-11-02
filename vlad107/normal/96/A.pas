var
  s:string;
  i,k:longint;

begin
  readln(s);
  k:=0;
  s:='!'+s;
  for i:=1 to length(s)do 
    if (s[i]=s[i-1])then inc(k)else begin
      if (k>6)then begin
        writeln('YES');
        exit;
      end;
      k:=1;
    end;
  if (k>6)then begin
    writeln('YES');
    exit;
  end;
  writeln('NO');
end.