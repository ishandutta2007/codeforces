const
  answers:array[1..4]of ansistring=('bus','ring','star','unknown');

var
  x,y,n,m,k1,i:longint;
  deg:array[0..500500]of longint;

  procedure return(x:longint);
    begin
      writeln(answers[x],' topology');
      halt(0);
    end;

begin
  read(n,m);
  for i:=1 to m do begin
    read(x,y);
    inc(deg[x]);
    inc(deg[y]);
  end;
  if (m>n)then return(4);
  if (m=n)then begin
    for i:=1 to n do 
      if (deg[i]<>2)then return(4);
    return(2);
  end;
  k1:=0;
  for i:=1 to n do 
    if (deg[i]=1)then inc(k1);
  if (k1=2)then begin
    for i:=1 to n do 
      if (deg[i]<>1)and(deg[i]<>2)then return(4);
    return(1);
  end;
  if (k1=n-1)then begin
    for i:=1 to n do
      if (deg[i]<>1)and(deg[i]<>n-1)then return(4);
    return(3);
  end;
  return(4);
end.