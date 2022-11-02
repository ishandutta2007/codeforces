{$r-,q-,s-,i-,o+}
var
  l,r:int64;
  pow10:array[0..50]of int64;
  i:longint;
  
  function f(n:int64):int64;
    var
      ct,ans,nn:int64;
      last,first,i,x,len,ln:longint;
      
    begin
      if (n=0)then begin
        f:=0;
        exit;
      end;
      while (true)do begin
        nn:=n;
        ln:=0;
        while (nn>0)do begin
          ln:=ln+1;
          nn:=nn div 10;
        end;
        first:=n div pow10[ln-1];
        last:=n mod 10;
        if (first=last)then break;
        n:=n-1;
      end;
      ans:=0;
      for i:=1 to 9 do 
        if (i<=n)then ans:=ans+1;
      nn:=n;
      for len:=2 to ln do begin
        for x:=1 to 9 do begin
          if (len<ln)or((len=ln)and(x<first))then begin
            ans:=ans+pow10[len-2];
            continue;
          end;
          if (x>first)then continue;
          ct:=x*pow10[len-2];
          ans:=ans+n div 10-ct+1;
        end;
      end;
      f:=ans;
    end;

begin
  read(l,r);
  pow10[0]:=1;
  for i:=1 to 18 do pow10[i]:=pow10[i-1]*10;
  writeln(f(r)-f(l-1));
end.