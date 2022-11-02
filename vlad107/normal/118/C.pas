{$r-,q-,s-,i-,o+}
var
  b,a:array[0..500500]of longint;
  kol:array[0..50]of longint;
  t,n,k,i,j,ans,nn,cr,pp,q:longint;
  ch:char;
  cs,s:ansistring;

begin
  readln(n,k);
  for i:=1 to n do begin
    read(ch);
    b[i]:=ord(ch)-48;
    inc(kol[b[i]]);
  end;
  ans:=1000000000;
  nn:=-1;
  for q:=0 to 9 do begin
    for i:=1 to n do a[i]:=b[i];
    i:=q-1;
    j:=q+1;
    pp:=kol[q];
    cr:=0;
    while (pp<k)do begin
      if (j<=9)then begin
        if (pp+kol[j]>k)then begin
          cr:=cr+(k-pp)*(j-q);
          for t:=1 to n do
            if (a[t]=j)and(pp<k)then begin
              a[t]:=q;
              inc(pp);
            end;
          break;
        end else begin
          cr:=cr+kol[j]*(j-q);
          pp:=pp+kol[j];
          for t:=1 to n do if (a[t]=j)then a[t]:=q;
        end;
      end;
      if (i>=0)then begin
        if (pp+kol[i]>k)then begin
          cr:=cr+(k-pp)*(q-i);
          for t:=n downto 1 do
            if (a[t]=i)and(pp<k)then begin
              a[t]:=q;
              inc(pp);
            end;
          break;
        end else begin
          cr:=cr+kol[i]*(q-i);
          pp:=pp+kol[i];
          for t:=1 to n do if (a[t]=i)then a[t]:=q;
        end;
      end;
      dec(i);inc(j);
    end;
    cs:='';
    for i:=1 to n do cs:=cs+chr(a[i]+48);
    if (cr<ans)or(cr=ans)and(cs<s)then begin
      ans:=cr;
      nn:=q;
      s:=cs;
    end;
  end;
  writeln(ans);
  writeln(s);
end.