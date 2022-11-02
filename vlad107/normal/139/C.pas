var
  n,k,i,j,q1,q2,q3,q4,q5,q6:longint;
  s:array[0..10500]of ansistring;
  a:array[0..500500]of longint;

  function rifm(a,b:ansistring):longint;
    var
      kk,i:longint;          
      ca,cb:ansistring;

    begin
      rifm:=1;
      ca:='';
      kk:=k;
      for i:=length(a) downto 1 do begin
        if (kk=0)then break;
        ca:=a[i]+ca;
        if (a[i]in['a','e','i','o','u'])then dec(kk);
      end;
      if (kk<>0)then rifm:=0;
      cb:='';
      kk:=k;
      for i:=length(b) downto 1 do begin
        if (kk=0)then break;
        cb:=b[i]+cb;
        if (b[i]in['a','e','i','o','u'])then dec(kk);
      end;
      if (kk<>0)then rifm:=0;
      if (ca<>cb)then rifm:=0;
    end;

begin
  readln(n,k);

  for i:=1 to n do begin
    for j:=1 to 4 do readln(s[j]);
    q1:=rifm(s[1],s[2]);
    q2:=rifm(s[1],s[3]);
    q3:=rifm(s[1],s[4]);
    q4:=rifm(s[2],s[3]);
    q5:=rifm(s[2],s[4]);
    q6:=rifm(s[3],s[4]);
    if (q1+q2+q3+q4+q5+q6=6)then a[i]:=0 else
    if (q1+q6=2)then a[i]:=1 else
    if (q2+q5=2)then a[i]:=2 else
    if (q3+q4=2)then a[i]:=3 else begin
      writeln('NO');
      exit;
    end;
  end;
  for i:=1 to n do for j:=i+1 to n do 
    if (a[i]<>a[j])and(a[i]<>0)and(a[j]<>0)then begin
      writeln('NO');
      exit;
    end;
  i:=1;
  while (i<n)and(a[i]=0)do inc(i);
  if (a[i]=0)then writeln('aaaa')else
  if (a[i]=1)then writeln('aabb')else
  if (a[i]=2)then writeln('abab')else
  if (a[i]=3)then writeln('abba');
end.