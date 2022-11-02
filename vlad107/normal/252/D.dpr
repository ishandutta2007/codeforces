var
  n,k,i,q,j:longint;
  ff:boolean;
  d,a,b,c:array[0..500500]of longint;
  
  procedure doit;
    var
      i:longint;
    begin
      for i:=1 to n do d[i]:=c[a[i]];
      for i:=1 to n do c[i]:=d[i];
    end;
    
  procedure dorev;
    var
      i:longint;
    begin
      for i:=1 to n do d[a[i]]:=c[i];
      for i:=1 to n do c[i]:=d[i];
    end;
    
  function eq:boolean;
    var
      i:longint;
    begin
      i:=1;
      while (i<=n)and(c[i]=b[i])do inc(i);
      eq:=i>n;
    end;
    
  procedure outp(s:string);
    begin
      writeln(s);
      halt(0);
    end;
    
  procedure solve;
    begin
      q:=0;
      for i:=1 to n do c[i]:=i;
      while (q<=k)do begin
        if (eq)then break;
        doit;inc(q);
      end;
      if (q<=k)and(q>0)and((k-q)mod 2=0)then begin
        for i:=1 to n do c[i]:=i;
        doit;
        ff:=eq;
        for i:=1 to n do c[i]:=i;
        dorev;
        if (not ff)or(not eq)or(k=q)then outp('YES');
      end;
    end;

begin
  read(n,k);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  solve;
  for i:=1 to n do d[a[i]]:=i;
  for i:=1 to n do a[i]:=d[i];
  solve;
  outp('NO');
end.