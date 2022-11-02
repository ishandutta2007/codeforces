var
  kt,n,m,i,j:longint;
  ch:char;
  tx,ty:array[0..500]of longint;
  
  function f(x,y,z:longint):longint;
    begin
      if (x=y)then f:=z else
      if (x=z)then f:=y else
      f:=x;
    end;

begin
  readln(n,m);
  kt:=0;
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(ch);
      if (ch='*')then begin
        inc(kt);
        tx[kt]:=i;ty[kt]:=j;
      end;
    end;
    readln;
  end;
  writeln(f(tx[1],tx[2],tx[3]),' ',f(ty[1],ty[2],ty[3]));
end.