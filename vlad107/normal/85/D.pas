{$r-,q-,s-,i-,o+}
type
  TTree=record
    kol:longint;
    sum:array[0..5]of int64;
  end;
var
  j,n,q,i,m,last:longint;
  tr:array[0..500500]of TTree;
  nomtr,nom,quest,a,b,c:array[0..500500]of longint;
  ch:char;
  procedure qs(l,r:longint);
    var
      i,j,xx,tmp:longint;
    begin
      i:=l;j:=r;
      xx:=b[(i+j)shr 1];
      while (i<=j)do begin
        while (xx>b[i])do inc(i);
        while (xx<b[j])do dec(j);
        if (i>j)then break;
        tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  procedure build(x,l,r:longint);
    var
      i:longint;
    begin
      tr[x].kol:=0;
      for i:=0 to 4 do tr[x].sum[i]:=0;
      if (l=r)
        then nomtr[l]:=x
        else begin
          build(x+x,l,(l+r)shr 1);
          build(x+x+1,(l+r)shr 1+1,r);
        end;
    end;
  procedure modify(q:longint);
    var
      i:longint;
    begin
      while (q>1)do begin
        q:=q shr 1;
        tr[q].kol:=tr[q+q].kol+tr[q+q+1].kol;
        for i:=0 to 4 do tr[q].sum[i]:=tr[q+q].sum[i];
        for i:=0 to 4 do tr[q].sum[(i+tr[q+q].kol)mod 5]:=tr[q].sum[(i+tr[q+q].kol)mod 5]+tr[q+q+1].sum[i];
      end;
    end;
begin
  readln(n);
  m:=0;
  for i:=1 to n do begin
    read(ch,ch,ch);
    case (ch)of
      'd':begin
            quest[i]:=1;
            readln(a[i]);
            inc(m);
            b[m]:=a[i];
            nom[m]:=i;
          end;
      'm':begin
            quest[i]:=2;
            readln;
          end;
      'l':begin
            quest[i]:=3;
            readln(a[i]);
            inc(m);
            b[m]:=a[i];
            nom[m]:=i;
          end;
    end;
  end;
  if (m=0)then begin
    for i:=1 to n do writeln(0);
    exit;
  end;
  qs(1,m);
  last:=b[1];
  b[1]:=1;
  c[nom[1]]:=1;
  for i:=2 to m do begin
    if (b[i]=last)
      then b[i]:=b[i-1] 
      else begin
        last:=b[i];
        b[i]:=b[i-1]+1;
      end;
    c[nom[i]]:=b[i];
  end;
  build(1,1,b[m]);
  for i:=1 to n do 
    case (quest[i])of
      2:writeln(tr[1].sum[3]);
      1:begin
          q:=nomtr[c[i]];
          tr[q].kol:=1;
          tr[q].sum[1]:=a[i];
          modify(q);
        end;
      3:begin
          q:=nomtr[c[i]];
          tr[q].kol:=0;
          for j:=0 to 4 do tr[q].sum[j]:=0;
          modify(q);
        end;
    end;
end.