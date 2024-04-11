var
  q:array[0..500500]of longint;
  ss,max,sum,a,b,n,i:longint;

begin
  read(n,a,b);
  if (b<10)then q[1]:=15 else q[1]:=1;
  sum:=q[1];
  for i:=2 to b+1 do begin
    q[i]:=sum+1;
    sum:=sum+q[i];
  end;
  ss:=b+2;
  if (b=0)
    then begin q[2]:=q[1]; ss:=b+3; end;
  for i:=ss to ss+a-1 do q[i]:=q[i-1]+1;
  for i:=ss+a to n do q[i]:=1;
  sum:=q[1];
  max:=q[1];
  for i:=2 to n do begin
    if (q[i]>sum)then dec(b) else
    if (q[i]>max)then dec(a);
    if (q[i]>max)then max:=q[i];
    inc(sum,q[i]);
  end;
  if (a<>0)or(b<>0)then begin
    writeln(-1);
    exit;
  end;
  for i:=1 to n do write(q[i],' ');
  writeln;
end.