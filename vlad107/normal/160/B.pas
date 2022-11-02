var
  p1,p2:ansistring;
  n,i,j:longint;
  ch:char;

begin
  readln(n);
  readln(p2);
  p1:=copy(p2,1,n); 
  delete(p2,1,n);
  for i:=1 to n-1 do 
    for j:=1 to n-1 do begin
      if (p1[j]>p1[j+1])then begin
        ch:=p1[j];p1[j]:=p1[j+1];p1[j+1]:=ch;
      end;
      if (p2[j]>p2[j+1])then begin
        ch:=p2[j];p2[j]:=p2[j+1];p2[j+1]:=ch;
      end;
    end;
  for i:=1 to n do 
    if (p1[i]=p2[i])then begin
      writeln('NO');
      exit;
    end;   
  for i:=2 to n do 
    if ((p1[i]>p2[i])<>(p1[1]>p2[1]))then begin
      writeln('NO');
      exit;
    end;
  writeln('YES');
end.