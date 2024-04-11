var
  n,i:longint;

  function rev(x:longint):longint;
    var
      ans:longint;
      
    begin
      ans:=0;
      while (x>0)do begin
        ans:=ans*10+x mod 10;
        x:=x div 10;
      end;
      rev:=ans;
    end;
  
  function prime(x:longint):boolean;
    var
      i:longint;
      
    begin
      i:=2;
      prime:=true;
      while (i*i<=x)do begin
        if (x mod i=0)then begin
          prime:=false;
          exit;
        end;
        inc(i);
      end;
    end;

begin
  read(n);
  for i:=11 to 1000000 do 
    if (prime(i))and(prime(rev(i)))and(rev(i)<>i)
      then begin
        dec(n);
        if (n=0)then begin
          writeln(i);
          exit;
        end;
      end;
end.