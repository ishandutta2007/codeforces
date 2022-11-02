{$r-,q-,s-,i-,o+}
var
  f,was:array[0..1 shl 20]of boolean;
  a,nom:array[0..10,0..10]of longint;
  mask,q,i,j,cx,cy,t:longint;
  s:string;
  xx,yy:array[0..50]of longint;

  procedure add(x,y:longint);
    begin
      inc(q);
      xx[q]:=x;
      yy[q]:=y;
      nom[x][y]:=q;
    end;

  function calc(mask:longint):boolean;
    var
      i,j,nm,cx,cy:longint;
      a:array[0..6,0..6]of longint;

    begin
      if (was[mask])then begin
        calc:=f[mask];
        exit;
      end;
      was[mask]:=true;
      fillchar(a,sizeof(a),$FF);
      for i:=1 to 19 do begin
        t:=(mask shr (i-1)) and 1;
        a[xx[i]][yy[i]]:=t;
      end;
      for i:=1 to 19 do begin
        cx:=xx[i];
        cy:=yy[i];
        nm:=mask;
        for j:=1 to 5 do begin
          if (a[cx][cy]<>1)then break;
          nm:=nm-(1 shl (nom[cx][cy]-1));
          if (not calc(nm))then begin
            f[mask]:=true;
            calc:=f[mask];
            exit;
          end;
          inc(cy);
        end;

        cx:=xx[i];
        cy:=yy[i];
        nm:=mask;
        for j:=1 to 5 do begin
          if (a[cx][cy]<>1)then break;
          nm:=nm-(1 shl (nom[cx][cy]-1));
          if (not calc(nm))then begin
            f[mask]:=true;
            calc:=f[mask];
            exit;
          end;
          inc(cx);
        end;

        cx:=xx[i];
        cy:=yy[i];
        nm:=mask;
        for j:=1 to 5 do begin
          if (a[cx][cy]<>1)then break;
          nm:=nm-(1 shl (nom[cx][cy]-1));
          if (not calc(nm))then begin
            f[mask]:=true;
            calc:=f[mask];
            exit;
          end;
          inc(cx);inc(cy);
        end;
      end;
      f[mask]:=false;
      calc:=f[mask];
    end;

begin
  q:=0;
  fillchar(nom,sizeof(nom),$FF);
  for i:=1 to 3 do add(1,i);
  for i:=4 to 7 do add(2,i-3);
  for i:=8 to 12 do add(3,i-7);
  for i:=13 to 16 do add(4,i-11);
  for i:=17 to 19 do add(5,i-14);
  q:=0;
  fillchar(a,sizeof(a),$FF);
  mask:=0;
  for i:=1 to 5 do begin
    readln(s);
    for j:=1 to length(s)do
      if (s[j]<>' ')then begin
        inc(q);
        cx:=xx[q];cy:=yy[q];
        if (s[j]='.')
          then a[cx][cy]:=0
          else begin
            a[cx][cy]:=1;
            mask:=mask+1 shl (q-1);
          end;
      end;
  end;
  fillchar(was,sizeof(was),false);
  was[0]:=true;
  f[0]:=false;

  if (calc(mask))
    then writeln('Karlsson')
    else writeln('Lillebror');
end.