var                   
  tmp,tt,k,x,y:longint;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(tt,k);
  while (tt>0)do begin
    dec(tt);
    read(x,y);      
    if (x>y)then begin
      tmp:=x;x:=y;y:=tmp;
    end;
    if (x mod (k+1)=0)
      then writeln('+')
      else begin
        if ((k<>1)and((y-x)and 1=((x-1-(x div (k+1)))div k)and 1))or
           ((k=1)and((y-x)and 1=0))
          then writeln('-')
          else writeln('+')
      end;
  end;
end.