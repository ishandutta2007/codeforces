{$r-,q-,s-,i-,o+}
const
  ccc=333;
  maxn=200500;

var
  sq:array[0..10,0..50]of int64;
  first,nom,a:array[0..maxn]of longint;
  f:array[0..6,0..maxn div ccc+5,0..12]of int64;
  l,r,ttk,tt,quest,new,tk,n,i,j:longint;
  ans:int64;
  
  procedure add(i,old,new:longint);
    var
      j,k,tk:longint;
      
    begin
      for j:=2 to 6 do 
        for k:=0 to 2*(j-1)-1 do begin
          tk:=(k+i-first[nom[i]])mod (2*(j-1));
          inc(f[j][nom[i]][k],sq[j][tk]*(new-old));
        end;
      a[i]:=new;
    end;

begin
  //assign(input,'input.txt');reset(input);
  read(n);
  for i:=1 to n do read(a[i]);
  
  for i:=2 to 6 do 
    for j:=0 to 2*(i-1)-1 do begin
      sq[i][j]:=j mod (2*(i-1));
      if (sq[i][j]=0)then sq[i][j]:=2 else
      if (sq[i][j]>i)then sq[i][j]:=2*i-sq[i][j];
    end;
  nom[0]:=0;
  for i:=1 to n do begin
    nom[i]:=nom[i-1]+ord(i mod ccc=1);
    if (nom[i]<>nom[i-1])then first[nom[i]]:=i;
  end;
  
  fillchar(f,sizeof(f),$0);
  for i:=1 to n do add(i,0,a[i]);
  
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(quest);
    if (quest=1)then begin
      read(i,new);
      add(i,a[i],new);
    end else begin
      read(l,r,j);
      tk:=1;
      ans:=0;
      while (l<=r)and(nom[l]=nom[l-1])do begin
        ans:=ans+sq[j][tk]*a[l];
        inc(l);
        inc(tk);
        if (tk=2*(j-1))then tk:=0;
      end;
      ttk:=(tk+r-l)mod(2*(j-1));
      while (l<=r)and(nom[r]=nom[r+1])do begin
        ans:=ans+sq[j][ttk]*a[r];
        dec(r);
        dec(ttk);
        if (ttk<0)then ttk:=2*(j-1)-1;
      end;
      if (l<=r)then begin
        for i:=nom[l] to nom[r] do begin
          ans:=ans+f[j][i][tk];
          tk:=(tk+ccc)mod (2*(j-1));
        end;
      end;
      writeln(ans);
    end;
  end;
end.