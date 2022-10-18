{$macro+}
{$undef debug}

{$ifdef debug}

const
  len=4;

{$else}

uses math;

const
  len=100000;

{$endif}


type
  el=record
    k,l,d:int64;
  end;

var
  i:longint;
  n,f,s:int64;
  a:array[1..len]of el;

    procedure sort(l,r: longint);
      var
         i,j,x: int64;
         y:el;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2].d;
         repeat
           while a[i].d>x do
            inc(i);
           while x>a[j].d do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

begin
  read(n,f);
  s:=0;
  for i:=1 to n do
    begin
      read(a[i].k,a[i].l);
      a[i].d:=max(min(a[i].k,a[i].l-a[i].k),0);
      inc(s,min(a[i].k,a[i].l))
    end;
  sort(1,n);
  for i:=1 to f do
    inc(s,a[i].d);
  writeln(s)
end.