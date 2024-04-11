uses
  math;

const
  maxn=100;

var
  n,w,i,s:longint;
  a,b,c:array[1..maxn]of longint;

procedure sorta(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                y:=c[i];
                c[i]:=c[j];
                c[j]:=y;
                inc(i);
                j:=j-1
             end;
         until i>j;
         if l<j then
           sorta(l,j);
         if i<r then
           sorta(i,r);
      end;

procedure sortc(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=c[(l+r) div 2];
         repeat
           while c[i]<x do
            inc(i);
           while x<c[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
                y:=c[i];
                c[i]:=c[j];
                c[j]:=y;
                inc(i);
                j:=j-1
             end;
         until i>j;
         if l<j then
           sortc(l,j);
         if i<r then
           sortc(i,r);
      end;

begin
  read(n,w);
  for i:=1 to n do
    begin
      read(a[i]);
      c[i]:=i;
    end;
  sorta(1,n);
  s:=0;
  for i:=1 to n do
    begin
      b[i]:=(a[i]+1) div 2;
      inc(s,b[i])
    end;
  if s>w then
    begin
      writeln(-1);
      halt
    end;
  for i:=n downto 1 do
    begin
      inc(b[i],min(w-s,a[i] div 2));
      inc(s,min(w-s,a[i] div 2))
    end;
  sortc(1,n);
  for i:=1 to n do
    write(b[i],' ');
  writeln
end.