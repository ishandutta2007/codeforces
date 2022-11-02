var
  ca,cb,ea,eb,x,i,lb,rb,a,b,tmp:longint;
  cm,max:int64;
  procedure solve;
    begin
      x:=1;
      for i:=1 to 31 do begin
        if (x>a)then break;
        lb:=trunc(0.8*x+0.99);
        rb:=trunc(1.25*x);
        if (rb>b)then rb:=b;
        if (lb<1)then lb:=1;
        if (rb<lb)then break;
        if (int64(x)*rb>max)or(int64(x)*rb=max)and((ca<0)and(x>ea)or(ca>0)and(rb>ea))then begin
          max:=int64(x)*rb;
          if (ca<0)then begin
            ea:=x;
            eb:=rb;
          end;
          if (ca>0)then begin
            ea:=rb;
            eb:=x;
          end;
        end;
        x:=x shl 1;
      end;
    end;
begin
  read(a,b);
  max:=0;
  ca:=-1;
  solve;
  tmp:=a;
  a:=b;
  b:=tmp;
  cm:=max;
  ca:=ea;cb:=eb;
  solve;
  writeln(ea,' ',eb);
end.