{$R-,S-,Q-,I-,O+}
var
  z: extended;
  res,s,w: array [0..1000010] of int64;
  left,right,st,a: array [0..1000010] of longint;
  q,tt,qq,max,min,n,i,e: longint;

procedure add(var a:int64;b:int64);
begin
  a:=a+b;
end;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  a[0]:=-1; a[n+1]:=-1;
  e:=1; st[1]:=0;
  for i:=1 to n do
  begin
    while (e > 1) and (a[st[e]] >= a[i]) do dec(e);
    left[i]:=i-st[e];
    inc(e);
    st[e]:=i;
  end;
  e:=1; st[1]:=n+1;
  for i:=n downto 1 do
  begin
    while (e > 1) and (a[st[e]] > a[i]) do dec(e);
    right[i]:=st[e]-i;
    inc(e);
    st[e]:=i;
  end;
  fillchar(s,sizeof(s),0);
  fillchar(w,sizeof(w),0);
  for i:=1 to n do
  begin
    max:=left[i]+right[i]-1;
    min:=left[i];
    if right[i] < min then min:=right[i];

    add(s[1],a[i]);
    add(s[min],-a[i]);

    add(w[min],int64(min)*a[i]);
    add(w[max-min+2],-int64(min)*a[i]);

    add(w[max-min+2],int64(max+1)*a[i]);
    add(w[max+1],-int64(max+1)*a[i]);

    add(s[max-min+2],-a[i]);
    add(s[max+1],a[i]);
  end;
  for i:=1 to n do
  begin
    add(s[i],s[i-1]);
    add(w[i],w[i-1]);
    res[i]:=w[i]+s[i]*i;
  end;
  read(tt);
  for qq:=1 to tt do
  begin
    read(q);
    z:=res[q];
    writeln(z/(n-q+1):0:17);
  end;
end.