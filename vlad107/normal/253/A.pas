var
  x,n,m,i:longint;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(n,m);
  if (n>=m)then x:=2 else x:=1;
  for i:=1 to n+m do begin
    x:=3-x;
    if (x=1)and(n>0)then begin write('B');dec(n);continue;end;
    if (x=2)and(m>0)then begin write('G');dec(m);continue;end;
    if (n=0)then begin write('G');continue; end;
    write('B');
  end;
  writeln;
end.