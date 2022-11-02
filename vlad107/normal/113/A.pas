const
  t:array[1..3,1..2]of ansistring=(('soil','alail'),('rte','arte'),('sitini','setini'));

var
  z,s:ansistring;
  x,y,j,n,i:longint;
  a:array[0..500500]of ansistring;
  u1,u2:array[0..500500]of longint;

begin
  readln(s);
  s:=s+' ';z:='';n:=0;
  for i:=1 to length(s)do
    if (s[i]<>' ')
      then z:=z+s[i]
      else begin
        inc(n);
        a[n]:=z;
        z:='';
      end;
  for i:=1 to n do begin
    s:='';
    for j:=1 to length(a[i])do s:=a[i][j]+s;
    u1[i]:=-1;
    for x:=1 to 3 do 
      for y:=1 to 2 do 
        if (length(s)>=length(t[x][y]))and(copy(s,1,length(t[x][y]))=t[x][y])
          then begin
            u1[i]:=x;
            u2[i]:=y;
          end;
    if (u1[i]=-1)then begin
      writeln('NO');
      exit;
    end;
  end;
  if (n=1)then begin
    writeln('YES');
    exit;
  end;
  j:=0;
  for i:=2 to n do begin
    if (u2[i]<>u2[1])or(u1[i]<u1[i-1])then begin
      writeln('NO');
      exit;
    end;
    if (u1[i]=2)then inc(j);
  end;
  if (u1[1]=2)then inc(j);
  if (j<>1)then begin
    writeln('NO');
    exit;
  end;
  for i:=2 to n do 
    if (u1[i]=u1[i-1])and(u1[i]=2)then begin
      writeln('NO');
      exit;
    end;
  writeln('YES');
end.