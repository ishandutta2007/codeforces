var
  u,i:longint;
  res,n,t:int64;
  f:array[0..555,0..555]of int64;
  pw:array[0..55]of int64;
  
  function min(x,y:int64):int64;
    begin
      if (x<y)then min:=x else min:=y;
    end;
  
  function calc(i,j:longint):int64;
    begin
      if (j<0)then begin
        calc:=0;
        exit;
      end;
      if (f[i][j]<>-1)then begin
        calc:=f[i][j];
        exit;
      end;
      if (i=0)or(j=0)then begin
        f[i][j]:=ord(j=0);
        calc:=f[i][j];
        exit;
      end;
      f[i][j]:=calc(i-1,j)+calc(i-1,j-1);
      calc:=f[i][j];
    end;
    
  function g(i,u:longint;n:int64):int64;
    var
      res:int64;
      
    begin
      if (n<=0)then begin
        g:=0;
        exit;
      end;
      if (n=pw[i])then begin
        g:=calc(i,u);
        exit;
      end;
      if (u=0)then begin
        g:=0;
        exit;
      end;
      res:=g(i-1,u,min(n,pw[i-1]));
      if (n>=pw[i-1])then res:=res+ord(u=1);
      res:=res+g(i-1,u-1,n-pw[i-1]);
      g:=res;
    end;

begin
  read(n,t);
  if (t and (t-1)<>0)then begin
    writeln(0);
    exit;
  end;
  u:=0;
  while (t mod 2=0)do begin
    inc(u);
    t:=t div 2;
  end;
  pw[0]:=1;
  for i:=1 to 50 do pw[i]:=pw[i-1]+pw[i-1];
  res:=0;
  fillchar(f,sizeof(f),$ff);
  for i:=0 to 50 do begin
    res:=res+g(i,u,min(n,pw[i]));
    n:=n-pw[i];
  end;
  writeln(res);
end.