uses
  math;
var
  q,x,y,k,t:longint;
  found:boolean;

begin
  read(x,y);
  q:=1;
  while (true)do begin
    if (q=1)then begin
      found:=false;
      for t:=min(2,x) downto 0 do begin
        k:=220-t*100;
        k:=k div 10;
        if (k<=y)then begin
          dec(x,t);
          dec(y,k);
          found:=true;
          break;
        end;
      end;
      if (not found)then begin
        writeln('Hanako');
        exit;
      end;
    end else begin
      found:=false;
      for k:=min(22,y) downto 0 do begin
        t:=220-k*10;
        if (t mod 100>0)then continue;
        t:=t div 100;
        if (t<=x)then begin
          dec(x,t);
          dec(y,k);
          found:=true;
          break;
        end;
      end;
      if (not found)then begin
        writeln('Ciel');
        exit;
      end;
    end;
    q:=1-q;
  end;
end.