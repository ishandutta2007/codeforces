#include <iostream>

std::string ans[10][10];

void init() {
ans[1][1] = "0\n.\n";
ans[1][2] = "0\n..\n";
ans[1][3] = "0\n...\n";
ans[1][4] = "0\n....\n";
ans[1][5] = "0\n.....\n";
ans[1][6] = "0\n......\n";
ans[1][7] = "0\n.......\n";
ans[1][8] = "0\n........\n";
ans[1][9] = "0\n.........\n";
ans[2][1] = "0\n.\n.\n";
ans[2][2] = "0\n..\n..\n";
ans[2][3] = "0\n...\n...\n";
ans[2][4] = "0\n....\n....\n";
ans[2][5] = "0\n.....\n.....\n";
ans[2][6] = "0\n......\n......\n";
ans[2][7] = "0\n.......\n.......\n";
ans[2][8] = "0\n........\n........\n";
ans[2][9] = "0\n.........\n.........\n";
ans[3][1] = "0\n.\n.\n.\n";
ans[3][2] = "0\n..\n..\n..\n";
ans[3][3] = "1\nBBB\n.B.\n.B.\n";
ans[3][4] = "1\nBBB.\n.B..\n.B..\n";
ans[3][5] = "2\nBBB.C\n.BCCC\n.B..C\n";
ans[3][6] = "2\nBBBCCC\n.B..C.\n.B..C.\n";
ans[3][7] = "3\nBBBDCCC\n.B.D.C.\n.BDDDC.\n";
ans[3][8] = "3\nBBBCCC.D\n.B..CDDD\n.B..C..D\n";
ans[3][9] = "4\nBBBECCC.D\n.B.E.CDDD\n.BEEEC..D\n";
ans[4][1] = "0\n.\n.\n.\n.\n";
ans[4][2] = "0\n..\n..\n..\n..\n";
ans[4][3] = "1\nBBB\n.B.\n.B.\n...\n";
ans[4][4] = "2\nBBB.\n.BC.\n.BC.\n.CCC\n";
ans[4][5] = "2\nBBB..\n.BCCC\n.B.C.\n...C.\n";
ans[4][6] = "3\nBBBCCC\n.BD.C.\n.BD.C.\n.DDD..\n";
ans[4][7] = "4\nBBBCCC.\n.BD.CE.\n.BD.CE.\n.DDDEEE\n";
ans[4][8] = "4\nBBBCCC..\n.BE.CDDD\n.BE.C.D.\n.EEE..D.\n";
ans[4][9] = "5\nBBBCCCDDD\n.BE.CF.D.\n.BE.CF.D.\n.EEEFFF..\n";
ans[5][1] = "0\n.\n.\n.\n.\n.\n";
ans[5][2] = "0\n..\n..\n..\n..\n..\n";
ans[5][3] = "2\nBBB\n.B.\nCB.\nCCC\nC..\n";
ans[5][4] = "2\nBBB.\n.B..\nCB..\nCCC.\nC...\n";
ans[5][5] = "4\nBBB.C\n.BCCC\nDB.EC\nDDDE.\nD.EEE\n";
ans[5][6] = "4\nBBBCCC\n.B..C.\nDB.EC.\nDDDEEE\nD..E..\n";
ans[5][7] = "5\nBBBCCC.\n.B..CE.\nDB.FCE.\nDDDFEEE\nD.FFF..\n";
ans[5][8] = "6\nBBBCCC.D\n.B..CDDD\nEB.FC.GD\nEEEFFFG.\nE..F.GGG\n";
ans[5][9] = "7\nBBBCCCD..\n.B..CFDDD\nEB.GCFDH.\nEEEGFFFH.\nE.GGG.HHH\n";
ans[6][1] = "0\n.\n.\n.\n.\n.\n.\n";
ans[6][2] = "0\n..\n..\n..\n..\n..\n..\n";
ans[6][3] = "2\nBBB\n.B.\nCB.\nCCC\nC..\n...\n";
ans[6][4] = "3\nBBB.\n.B..\nCB..\nCCCD\nCDDD\n...D\n";
ans[6][5] = "4\nBBB..\n.BCCC\nDB.C.\nDDDCE\nD.EEE\n....E\n";
ans[6][6] = "5\nBBBCCC\n.BD.C.\n.BD.C.\nEDDD.F\nEEEFFF\nE....F\n";
ans[6][7] = "6\nBBB.CCC\n.BD..C.\n.BDDDC.\nF.DGEEE\nFFFG.E.\nF.GGGE.\n";
ans[6][8] = "7\nBBBCCC..\n.BE.CDDD\n.BE.C.D.\nFEEEH.DG\nFFF.HGGG\nF..HHH.G\n";
ans[6][9] = "8\nBBBCCCDDD\n.BE.C..D.\n.BE.CF.D.\nGEEEIFFFH\nGGG.IFHHH\nG..III..H\n";
ans[7][1] = "0\n.\n.\n.\n.\n.\n.\n.\n";
ans[7][2] = "0\n..\n..\n..\n..\n..\n..\n..\n";
ans[7][3] = "3\nBBB\n.B.\nCB.\nCCC\nC.D\nDDD\n..D\n";
ans[7][4] = "4\nBBB.\n.BC.\n.BC.\nDCCC\nDDDE\nDEEE\n...E\n";
ans[7][5] = "5\nBBB..\n.BCCC\nDB.C.\nDDDC.\nDFEEE\n.F.E.\nFFFE.\n";
ans[7][6] = "6\nBBBCCC\n.B..C.\nDB.EC.\nDDDEEE\nDF.EG.\n.FFFG.\n.F.GGG\n";
ans[7][7] = "8\nBBB.CCC\n.BDDDC.\nEB.D.CF\nEEEDFFF\nEHGGGIF\n.H.G.I.\nHHHGIII\n";
ans[7][8] = "9\nBBB.CCC.\n.BDDDCF.\n.BED.CF.\nEEEDGFFF\nH.EJGGGI\nHHHJGIII\nH.JJJ..I\n";
ans[7][9] = "10\nBBB.CCC..\n.BDDDCEEE\nFB.D.CGE.\nFFFDGGGE.\nFJHHHKG.I\n.J.H.KIII\nJJJHKKK.I\n";
ans[8][1] = "0\n.\n.\n.\n.\n.\n.\n.\n.\n";
ans[8][2] = "0\n..\n..\n..\n..\n..\n..\n..\n..\n";
ans[8][3] = "3\nBBB\n.B.\nCB.\nCCC\nC..\nDDD\n.D.\n.D.\n";
ans[8][4] = "4\nBBB.\n.B..\nCB..\nCCC.\nCDDD\n.ED.\n.ED.\nEEE.\n";
ans[8][5] = "6\nBBB..\n.BCCC\nDB.C.\nDDDCE\nD.EEE\nFFFGE\n.F.G.\n.FGGG\n";
ans[8][6] = "7\nBBBCCC\n.B..C.\nDB.EC.\nDDDEEE\nD.FE..\n.HFFFG\n.HFGGG\nHHH..G\n";
ans[8][7] = "9\nBBB.CCC\n.BDDDC.\nEB.DFC.\nEEEDFFF\nEGGGF.H\n.JGIHHH\n.JGIIIH\nJJJI...\n";
ans[8][8] = "10\nBBBCCC..\n.B..CDDD\nEB..C.D.\nEEEFFFDH\nEGGGFHHH\n.JGIF.KH\n.JGIIIK.\nJJJI.KKK\n";
ans[8][9] = "12\nBBBCCC..D\n.BF.CEDDD\n.BF.CEEED\nHFFFIEGGG\nHHHJIIIG.\nHL.JIM.GK\n.LJJJMKKK\nLLL.MMM.K\n";
ans[9][1] = "0\n.\n.\n.\n.\n.\n.\n.\n.\n.\n";
ans[9][2] = "0\n..\n..\n..\n..\n..\n..\n..\n..\n..\n";
ans[9][3] = "4\nBBB\n.B.\nCB.\nCCC\nC.D\nDDD\nE.D\nEEE\nE..\n";
ans[9][4] = "5\nBBB.\n.B..\nCB..\nCCCD\nCDDD\nEEED\n.EF.\n.EF.\n.FFF\n";
ans[9][5] = "7\nBBB..\n.BCCC\nDB.C.\nDDDCE\nDFEEE\n.FFFE\nHFGGG\nHHHG.\nH..G.\n";
ans[9][6] = "8\nBBBCCC\n.B..C.\nDB.EC.\nDDDEEE\nD.FE..\nFFFGGG\nH.FIG.\nHHHIG.\nH.III.\n";
ans[9][7] = "10\nBBBCCC.\n.B..CE.\nDB.FCE.\nDDDFEEE\nDGFFF.H\n.GGGHHH\nJGIIIKH\nJJJI.K.\nJ..IKKK\n";
ans[9][8] = "12\nBBBCCC.D\n.BE.CDDD\n.BE.C.FD\nGEEEFFF.\nGGGHHHFJ\nGIIIHJJJ\n.LIKH.MJ\n.LIKKKM.\nLLLK.MMM\n";
ans[9][9] = "13\nBBBCCCDDD\n.BE.CF.D.\n.BE.CF.D.\nGEEEFFF.I\nGGGHHHIII\nGJJJHKKKI\n.MJLH.KN.\n.MJLLLKN.\nMMML..NNN\n";
}

int main() {
	init();
	int n, m;
	std::cin >> n >> m;
	for(auto a : ans[n][m]) {
		if('A' <= a && a <= 'Z') std::cout << char(a - 1);
		else std::cout << a;
	}
}