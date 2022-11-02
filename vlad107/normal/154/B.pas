{$r-,q-,s-,i-,o+}
var
  was:array[0..500500]of longint;
  wasx:array[0..500500]of boolean;
  nom,x,n,m,i:longint;
  ch:char;

  procedure add(x:longint);
    var
      i:longint;
    begin
      if (wasx[x])then begin
        writeln('Already on');
        exit;
      end;
      
      nom:=x;
      i:=2;
      while (i*i<=nom)do begin
        if (x mod i=0)then begin
          if (was[i]<>0)then begin
		    writeln('Conflict with ',was[i]);
		    exit;
          end;
          while (x mod i=0)do x:=x div i;
        end;
        inc(i);
      end;
      if (x>1)then begin
        if (was[x]<>0)then begin
		  writeln('Conflict with ',was[x]);
		  exit;
        end;
      end;        
        
      x:=nom;
      wasx[x]:=true;
      writeln('Success');
      i:=2;
      while (i*i<=nom)do begin
        if (x mod i=0)then begin
          was[i]:=nom;
          while (x mod i=0)do x:=x div i;
        end;
        inc(i);
      end;
      if (x>1)then was[x]:=nom;
    end;
    
  procedure erase(x:longint);
    var
      i:longint;
    begin
      if (wasx[x]=false)then begin
        writeln('Already off');
        exit;
      end;
      writeln('Success');
      wasx[x]:=false;
      i:=2;
      nom:=x;
      while (i*i<=nom)do begin
        if (x mod i=0)then begin
          was[i]:=0;
          while (x mod i=0)do x:=x div i;
        end;
        inc(i);
      end;    
      if (x>1)then was[x]:=0;
    end;

begin
  readln(n,m);
  for i:=1 to m do begin
    readln(ch,x);
    if (ch='+')then add(x) else erase(x);
  end;
end.