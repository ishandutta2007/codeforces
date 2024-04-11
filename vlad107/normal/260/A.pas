{$r-,q-,s-,i-,o+}
var
  ans:ansistring;
  i,c,a,b,n:longint;
  found:boolean;

begin
  read(a,b,n);
  str(a,ans);
  a:=a mod b;
  for i:=1 to n do begin
    found:=false;
    for c:=0 to 9 do 
      if ((a*10+c)mod b=0)then begin
        ans:=ans+chr(c+48);
        a:=0;
        found:=true;
        break;
      end;
    if (not found)then begin
      writeln(-1);
      exit;
    end;
  end;
  writeln(ans);
end.