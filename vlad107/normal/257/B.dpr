
{$r-,q-,s-,i-,o+}
var
  an,am,n,m,kn,km,cn,cm,i:longint;
  a:array[0..500500]of longint;
  
  procedure solve;
    begin
      cn:=0;cm:=0;
      for i:=2 to n+m do
        if (i and 1=0)then begin
          if ((a[i-1]=1)and(km<m))or(kn=n)then begin
            if (a[i-1]=1)then inc(cm) else inc(cn);
            inc(km);
            a[i]:=2;
          end else begin
            if (a[i-1]=2)then inc(cm) else inc(cn);
            inc(kn);
            a[i]:=1;
          end;
        end else begin
          if ((a[i-1]=1)and(kn<n))or(km=m)then begin
            if (a[i-1]=1)then inc(cn) else inc(cm);
            inc(kn);
            a[i]:=1;
          end else begin
            if (a[i-1]=2)then inc(cn) else inc(cm);
            inc(km);
            a[i]:=2;
          end;
        end;
    end;

begin
  read(n,m);
  a[1]:=1;kn:=1;km:=0;
  solve;
  an:=cn;am:=cm;
  a[1]:=2;kn:=0;km:=1;
  solve;
  if (cn>an)or((cn=an)and(cm<am))then begin
    an:=cn;am:=cm;
  end;
  writeln(an,' ',am);
end.