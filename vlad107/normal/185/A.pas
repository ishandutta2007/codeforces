const
  base=1000000007;

var
  n:int64;
  
  function pow(x,y:int64):longint;
    var
      a:int64;
      
    begin
      if (y=0)then begin
        pow:=1;
        exit;
      end;
      if (y mod 2=0)then begin
        a:=pow(x,y div 2)mod base;
        pow:=a*a mod base;
      end else begin
        a:=pow(x,y-1)mod base;
        pow:=a*x mod base;
      end;
    end;

begin
  read(n);
  if (n=0)
    then writeln(1)
    else writeln((pow(2,2*n-1)+pow(2,n-1))mod base);
end.