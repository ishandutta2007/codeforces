var
  u,n,k,i,j:longint;
  q,a:array[0..500500]of longint;
  
  function bit(x,t:longint):longint;
    begin
      if (x and (1 shl t)=0)then bit:=0 else bit:=1;
    end;

begin
  read(n,k);
  for i:=1 to n do a[i]:=ord(i<>1);
  for i:=0 to k-1 do begin
    for j:=1 to n do begin
      if (bit(a[j],i)<>bit(j-1,i))then u:=(1 shl i)+1 else u:=1;
      inc(a[j],a[u]);
      q[n-j+1]:=n-u+1;
    end;
    for j:=1 to n do write(q[j],' ');
    writeln;
  end;
end.