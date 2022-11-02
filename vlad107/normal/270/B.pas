var
  ans,i,n:longint;
  sa,a:array[0..500500]of longint;
  
  procedure modify(x:longint);
    begin
      while (x<=500500)do begin
        inc(sa[x]);
        x:=x or (x-1)+1;
      end;
    end;
    
  function fs(x:longint):longint;
    var
      res:longint;
      
    begin
      res:=0;
      while (x>0)do begin
        inc(res,sa[x]);
        x:=x and (x-1);
      end;
      fs:=res;
    end;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  ans:=0;
  for i:=1 to n do begin
    if (fs(a[i])+1<>a[i])then ans:=i;
    modify(a[i]);
  end;
  writeln(ans);
end.