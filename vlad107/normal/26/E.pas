var
  u,a:array[0..500500]of longint;
  y,nom,i,min,sum,x,n,w:longint;

  procedure doit(x:longint);
    begin 
      if (a[x] and 1=0)then u[x]:=y else y:=u[x]+1;
      dec(a[x]);
      write(x,' ');
    end;

begin
  read(n,w);
  sum:=0;min:=maxlongint;
  for i:=1 to n do begin
    read(a[i]);
    inc(sum,a[i]);
    if (a[i]<min)then begin
      min:=a[i];nom:=i;
    end;
    a[i]:=2*a[i];
  end;
  if ((w=1)and(min<>1))or(w<=0)or(w>sum)or((w<>sum)and(n=1))then begin writeln('No');exit;end;
  writeln('Yes');
  if (w<min)then begin
    if (nom=1)then x:=2 else x:=1;
    doit(x);
    for i:=1 to 2*(min-w+1)do doit(nom);
    doit(x);
    sum:=0;
    for i:=1 to n do inc(sum,a[i] div 2);
  end;
  doit(nom);
  x:=sum-w+y;
  for i:=1 to n do 
    if (i<>nom)then begin
      while (a[i]>0)and(x>0)do begin
        if (a[i] and 1=1)then dec(x);
        doit(i);
      end;
    end;
  doit(nom);
  for i:=1 to n do while (a[i]>0)do doit(i);
  writeln;
  //writeln(y);
end.