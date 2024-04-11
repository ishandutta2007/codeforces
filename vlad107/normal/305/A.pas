var
  k0,n,i,j,k:longint;
  a:array[0..500500]of longint;
  
  function check(x,y:longint):boolean;
    begin
      check:=false;
      if (x=0)or(y=0)Then exit;
      while (x>0)or(y>0)do begin
        if (x mod 10<>0)and(y mod 10<>0)then exit;
        x:=x div 10;y:=y div 10;
      end;
      check:=true;
    end;
    
  procedure out0;
    var
      i:longint;
    begin
      for i:=1 to n do 
        if (a[i]=0)then write(0,' ');
      writeln;
      halt(0);
    end;
  

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do 
    if (a[i]=0)then inc(k0);
  for i:=1 to n do 
    for j:=i+1 to n do 
      for k:=j+1 to n do 
        if (check(a[i],a[j]))and(check(a[i],a[k]))and(check(a[j],a[k]))then begin
          writeln(3+k0);
          write(a[i],' ',a[j],' ',a[k],' ');
          out0;
        end;
  for i:=1 to n do 
    for j:=i+1 to n do 
      if (check(a[i],a[j]))then begin
        writeln(2+k0);
        write(a[i],' ',a[j],' ');
        out0;
      end;
  for i:=1 to n do
    if (a[i]<>0)then begin
      writeln(1+k0);
      write(a[i],' ');
      out0;
    end;
  writeln(k0);
  out0;
end.