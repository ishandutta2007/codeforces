type
  foot=record
    p,a,b:longint
  end;

var
  n,m,i,c:longint;
  a:array[1..200000]of foot;
  b:array[1..3,1..200000]of longint;
  f:array[1..200000]of boolean;
  p:array[1..3]of longint;

procedure Sort(L, R : Longint);
var
  i, j, x: longint;
  t:foot;
begin
  i := L; 
  j := R; 
  x := a[(i + j)div 2].p;
  repeat
    while a[i].p < x do inc(i);
    while a[j].p > x do dec(j);
    if i <= j then begin
      t := a[i]; 
      a[i] := a[j]; 
      a[j] := t;
      inc(i); 
      dec(j);
    end;
  until i > j;
  if i < R then Sort(i, R);
  if j > L then Sort(L, j);
end;

begin
  read(n);
  for i:=1 to n do
    read(a[i].p);
  for i:=1 to n do
    read(a[i].a);
  for i:=1 to n do
    read(a[i].b);
  sort(1,n);
  p[1]:=1;
  p[2]:=1;
  p[3]:=1;
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
    begin
      b[a[i].a,p[a[i].a]]:=i;
      inc(p[a[i].a]);
      if a[i].a<>a[i].b then
        begin
          b[a[i].b,p[a[i].b]]:=i;
          inc(p[a[i].b]);
        end
    end;
  fillchar(f,sizeof(f),0);
  p[1]:=1;
  p[2]:=1;
  p[3]:=1;
  read(m);
  for i:=1 to m do
    begin
      read(c);
      while (b[c,p[c]]<>0)and(f[b[c,p[c]]]) do
        inc(p[c]);
      if b[c,p[c]]=0
        then write('-1 ')
        else
          begin
            write(a[b[c,p[c]]].p,' ');
            f[b[c,p[c]]]:=true;
            inc(p[c])
          end
    end
end.