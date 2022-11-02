var
  a,b,i:longint;
  function prime(x:longint):boolean;
    var
      i:longint;
    begin
      prime:=false;
      for i:=2 to x-1 do 
        if (x mod i=0)then exit;
      prime:=true;
    end;
begin
  read(a,b);
  for i:=a+1 to b-1 do 
    if (prime(i))then begin
      writeln('NO');
      exit;
    end;
  if (not prime(b))
    then writeln('NO')
    else writeln('YES');
end.