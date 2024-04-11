var
  w,b,ww,bb,nw,nb,nom:longint;
  ans,nf:extended;
  f:array[0..1,0..1111,0..1111]of extended;

begin
  read(w,b);
  f[0][w][b]:=1.0;
  ans:=0;
  for ww:=w downto 0 do 
    for bb:=b downto 0 do for nom:=0 to 1 do begin
      if (ww>0)and(nom=0)then ans:=ans+f[nom][ww][bb]*ww/(ww+bb);
      if (bb=0)then continue;
      nw:=ww;nb:=bb-1;
      nf:=f[nom][ww][bb]*bb/(ww+bb);
      if (nom=0)then begin
        f[1-nom][nw][nb]:=f[1-nom][nw][nb]+nf;
        continue;
      end;
      if (nw>0)then f[1-nom][nw-1][nb]:=f[1-nom][nw-1][nb]+nf*nw/(nw+nb);
      if (nb>0)then f[1-nom][nw][nb-1]:=f[1-nom][nw][nb-1]+nf*nb/(nw+nb);
    end;
  writeln(ans:0:10);
end.