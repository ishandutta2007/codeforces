var
  l,r:int64;

  function f(n:int64):int64;
    var
      q,t,k:longint;
      st,u,nn,res:int64;
      
    begin
      if (n<3)then begin
        f:=0;
        exit;
      end;
      nn:=n;k:=0;
      while (nn>1)do begin
        inc(k);
        nn:=nn div 2;
      end;
      st:=(int64(1) shl k)-1;
      res:=f(st);
      inc(k);
      for t:=1 to k-1 do 
        if (k mod t=0)then begin
          u:=0;
          for q:=0 to k div t-1 do 
            u:=u+int64(1)shl (q*t);
          if (u>n)then continue;
          res:=res+(n div u)-f(n div u);
          res:=res-(st div u)+f(st div u);
        end;
      f:=res;
    end;

begin
  read(l,r);
  writeln(f(r)-f(l-1))
end.