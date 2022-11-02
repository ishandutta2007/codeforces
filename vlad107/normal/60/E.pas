
type
  matr=array[1..2,1..2]of longint;
var
  wwn,ai,bi,i,sum,rx,n,base:longint;
  x,y:int64;
  a:matr;
  ww:array[0..1001000]of longint;
  function pow(x:longint;y:int64):longint;
    var
      res:longint;
    begin
      res:=1;
      while (y>0)do begin
        if (y mod 2=1)then res:=int64(res)*x mod base;
        x:=int64(x)*x mod base;
        y:=y div 2;
      end;
      pow:=res;
    end;
  procedure mulmatr(a,b:matr;var c:matr);
    var
      i,j,k:longint;
    begin
      for i:=1 to 2 do 
        for j:=1 to 2 do begin
          c[i][j]:=0;
          for k:=1 to 2 do c[i][j]:=(c[i][j]+int64(a[i][k])*b[k][j]mod base)mod base; 
        end;
    end;
  function calc(x,y:longint;t:int64):longint;
    var
      rr,res:longint;
      r:matr;
    begin
      if (t=0)then begin
        calc:=x;
        exit;
      end;
      res:=pow(3,t);
      res:=int64(res)*x mod base;
      a[1][1]:=3;
      a[1][2]:=0;
      a[2][1]:=1;
      a[2][2]:=1;
      r[1][1]:=1;
      r[1][2]:=0;
      r[2][1]:=0;
      r[2][2]:=1;
      while (t>0)do begin
        if (t mod 2=1)then mulmatr(a,r,r);
        mulmatr(a,a,a);
        t:=t div 2;
      end;
      rr:=int64(r[2][1])*y mod base;
      res:=(res-rr+base)mod base;
      calc:=res;
    end;
  function cmp(x1,y1,x2,y2:int64;k:longint):boolean;
    begin
      if (k=0)then begin
        cmp:=y1>y2;
        exit;
      end;
      if ((x1>x2)and(y1<y2))or
         ((x1<x2)and(y1>y2))then begin
           cmp:=cmp(y1,x1+y1,y2,x2+y2,k-1);
           exit;
         end;
      if (x1>x2)or(x1=x2)and(y1>y2)
        then cmp:=true else cmp:=false;
    end;
  function fib(f1,f2:longint;x:int64):longint;
    var
      r:matr;
    begin
      if (x=0)then begin
        fib:=f2;
        exit;
      end;
      if (x=1)then begin
        fib:=(f1+f2)mod base;
        exit;
      end;
      a[1][1]:=0;
      a[1][2]:=1;
      a[2][1]:=1;
      a[2][2]:=1;
      r[1][1]:=1;
      r[1][2]:=0;
      r[2][1]:=0;
      r[2][2]:=1;
      while (x>0)do begin
        if (x mod 2=1)then mulmatr(a,r,r);
        mulmatr(a,a,a);
        x:=x div 2;
      end;
      fib:=((int64(r[2][1])*f1 mod base)+(int64(r[2][2])*f2 mod base))mod base;
    end;
begin
  read(n,x,y,base);
  sum:=0;
  for i:=1 to n do begin
    read(ww[i]);
    sum:=(sum+ww[i])mod base;
  end;
  rx:=calc(sum,(ww[1]+ww[n])mod base,x);
  ai:=ww[1];bi:=ww[2];
  for i:=3 to n do
    if (cmp(ww[i-1],ww[i],ai,bi,x))then begin
      ai:=ww[i-1];
      bi:=ww[i];
    end;
  wwn:=fib(ai,bi,x);
  writeln(calc(rx,(ww[1]+wwn)mod base,y));
end.