{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  nd,aa,bb,kq,n,m,i,ii,e,j,u,w,kd: longint;
  fine,found: boolean;
  z: int64;
  q,d,ans,ss,ff,gcd,lcm,pred,last,x: array [0..100010] of longint;
  was: array [0..100010] of boolean;
begin
//  assign(input,'a'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  for i:=1 to m do read(ss[i],ff[i],gcd[i],lcm[i]);
  for i:=1 to m do
  begin
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
    gcd[i+m]:=gcd[i];
    lcm[i+m]:=lcm[i];
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(was,sizeof(was),False);
  for ii:=1 to n do
    if not was[ii] then
    begin
      i:=1; e:=1;
      x[1]:=ii;
      was[ii]:=True;
      while i <= e do
      begin
        j:=last[x[i]];
        while j > 0 do
        begin
          if not was[ff[j]] then
          begin
            inc(e);
            x[e]:=ff[j];
            was[x[e]]:=True;
          end;
          j:=pred[j];
        end;
        inc(i);
      end;
      if e = 1 then ans[ii]:=1 else
      begin
        u:=lcm[last[ii]];
        kd:=0;
        for w:=1 to u do
          if int64(w)*w > u then continue else
          if u mod w = 0 then
          begin
            inc(kd);
            d[kd]:=w;
            if int64(w)*w < u then
            begin
              inc(kd);
              d[kd]:=u div w;
            end;
          end;
        kq:=e;
        for i:=1 to kq do q[i]:=x[i];
        found:=False;
        for nd:=1 to kd do
        begin
          for i:=1 to kq do ans[q[i]]:=0;
          ans[ii]:=d[nd];
          fine:=True;
          i:=1; e:=1;
          x[1]:=ii;
          while i <= e do
          begin
            j:=last[x[i]];
            while j > 0 do
            begin
              if ans[ff[j]] = 0 then
              begin
                z:=int64(gcd[j])*lcm[j] div ans[x[i]];
                if z > round(1e6) then
                begin
                  fine:=False;
                  break;
                end;
                if z = 0 then z:=1;
                inc(e);
                x[e]:=ff[j];
                ans[x[e]]:=z;
              end;
              j:=pred[j];
            end;
            if not fine then break;
            inc(i);
          end;
          if not fine then continue;
          for i:=1 to e do
          begin
            j:=last[x[i]];
            while j > 0 do
            begin
              u:=ans[x[i]];
              w:=ans[ff[j]];
              aa:=u; bb:=w;
              while (aa > 0) and (bb > 0) do
                if aa > bb then aa:=aa mod bb
                else bb:=bb mod aa;
              if (aa+bb <> gcd[j]) or (int64(u)*w div (aa+bb) <> lcm[j]) then
              begin
                fine:=False;
                break;
              end;
              j:=pred[j];
            end;
            if not fine then break;
          end;
          if not fine then continue;
          found:=True;
          break;
        end;
        if not found then
        begin
          writeln('NO');
          halt;
        end;
      end;
    end;
  writeln('YES');
  for i:=1 to n-1 do write(ans[i],' ');
  writeln(ans[n]);
  close(input);
  close(output);
end.