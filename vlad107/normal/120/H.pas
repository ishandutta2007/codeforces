{$r-,q-,s-,i-,o+}
var
  used:array[0..500500]of boolean;
  o,cr,x,tn,kn,pn,nom,n,i,kb,j:longint;
  res,kq:array[0..500500]of longint;
  kolb:array[0..1700000]of longint;
  sq:array[0..500,0..500]of string[7];
  a:array[0..500]of string[25];
  next:array[0..1700000,'a'..'z']of longint;
  procedure rec(x,k:longint;s:string);
    var
      j:longint;
    begin
      if (k>4)then exit;
      if (x>length(a[i]))then begin
        if (s<>'')then begin
          for j:=1 to kq[i]do if (sq[i][j]=s)then exit;
          inc(kq[i]);sq[i][kq[i]]:=s;
        end;
        exit;
      end;
      rec(x+1,k,s);
      rec(x+1,k+1,s+a[i][x]);
    end;
  procedure add(s:string;val:longint);
    var
      i,j:longint;
    begin
      j:=0;
      for i:=1 to length(s)do begin
        if (next[j][s[i]]=0)then begin
          inc(kb);
          next[j][s[i]]:=kb;
        end;
        j:=next[j][s[i]];
      end;
      if (val=0)then kolb[j]:=0 else inc(kolb[j],val);
      if (kolb[j]<0)then kolb[j]:=0;
    end;
  function kol(s:string):longint;
    var
      i,j:longint;
    begin
      j:=0;
      for i:=1 to length(s)do j:=next[j][s[i]];
      kol:=kolb[j];
    end;
begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  readln(n);
  for i:=1 to n do readln(a[i]);
  for i:=1 to n do rec(1,0,'');
  kb:=0;
  for i:=1 to n do
    for j:=1 to kq[i] do add(sq[i][j],1);
  fillchar(used,sizeof(used),false);
  for i:=1 to n do begin
    pn:=1000000;
    x:=0;
    for j:=1 to n do begin
      if (used[j])then continue;
      cr:=0;
      for o:=1 to kq[j]do if (kol(sq[j][o])<>0)then inc(cr);
      if (cr<pn)then begin
        pn:=cr;
        x:=j;
      end;
    end;
    used[x]:=true;
    nom:=-1;
    kn:=0;
    pn:=1000000;
    for j:=1 to kq[x] do begin
      tn:=kol(sq[x][j]);
      if (tn<>0)and(tn<pn)or((tn=pn)and(length(sq[x][j])>kn))then begin
        kn:=length(sq[x][j]);
        nom:=j;
        pn:=tn;
      end;
    end;
    if (nom<0)then begin
      writeln(-1);
      exit;
    end;
    res[x]:=nom;
    add(sq[x][nom],0);
    for j:=1 to kq[x]do if (j<>nom)then add(sq[x][j],-1);
  end;
  for i:=1 to n do writeln(sq[i][res[i]]);
  close(output);close(input);
end.