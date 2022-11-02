{$r-,q-,s-,i-,o+}
{$M 10000000}
var
  res,ressimp,n,na,nb,i:longint;
  was,kol,kolb:array[0..100500]of longint;
  g:array[0..1111,0..1111]of longint;
  a,b:string;

  function nom(s:string):longint;
    begin
      if (s='Anka')then nom:=1 else
      if (s='Chapay')then nom:=2 else
      if (s='Cleo')then nom:=3 else
      if (s='Troll')then nom:=4 else
      if (s='Dracul')then nom:=5 else
      if (s='Snowy')then nom:=6 else
      nom:=7;
    end;

  procedure rec(x:longint);
    var
      j,i,min,max,ct,simp:longint;
    begin
      if (x>7)then begin
        if (kol[1]*kol[2]*kol[3]=0)then exit;
        min:=maxlongint;
        max:=-maxlongint;
        for i:=1 to 7 do begin
          ct:=kolb[was[i]]div kol[was[i]];
          if (ct<min)then min:=ct;
          if (ct>max)then max:=ct;
        end;
        simp:=0;
        for i:=1 to 7 do
          for j:=1 to 7 do
            if (g[i][j]>0)and(was[i]=was[j])
              then inc(simp);
        if (max-min<res)or(max-min=res)and(simp>ressimp)
          then begin
            res:=max-min;
            ressimp:=simp;
          end;
        exit;
      end;
    for i:=1 to 3 do begin
      was[x]:=i;
      inc(kol[i]);
      rec(x+1);
      dec(kol[i]);
      was[x]:=0;
    end;
  end;

begin
  readln(n);
  for i:=1 to n do begin
    readln(b);
    a:=copy(b,1,pos(' ',b)-1);
    delete(b,1,pos(' ',b));
    delete(b,1,pos(' ',b));
    na:=nom(a);
    nb:=nom(b);
    inc(g[na][nb]);
  end;
  for i:=1 to 3 do read(kolb[i]);
  res:=maxlongint;
  rec(1);
  writeln(res,' ',ressimp);
end.